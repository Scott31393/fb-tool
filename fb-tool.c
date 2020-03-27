#include <linux/fb.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <inttypes.h>
#include <stdio.h>

uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo)
{
	return (r<<vinfo->red.offset) | (g<<vinfo->green.offset) | (b<<vinfo->blue.offset);
}

int main()
{
	struct fb_fix_screeninfo finfo;
	struct fb_var_screeninfo vinfo;
	int fb_fd = open("/dev/fb0",O_RDWR);
    int user_grayscale;
    int user_bpp;
    int user_line_number;
    
    printf("Choose bpp \n");
    scanf("%d", &user_bpp);
    printf("you choose bpp = %d \n", user_bpp);
    printf("Choose grayscale option (0=color) (1=grayscale)\n");
    scanf("%d", &user_grayscale);
    printf("you choose grayscale option = %d \n", user_grayscale);

	//Get variable screen information
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
	vinfo.grayscale=user_grayscale;
	vinfo.bits_per_pixel=user_bpp;


	ioctl(fb_fd, FBIOPUT_VSCREENINFO, &vinfo);
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
	ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);

    printf("finfo.line_length in byte= %d \n", finfo.line_length);
    

    /* length of a line in bytes    */
	long screensize = vinfo.yres_virtual * finfo.line_length;
    printf("screensize in byte= %ld \n", screensize);

    /*pointe to framebuffer*/
	uint8_t *fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, (off_t)0);

	

    printf("Screen dimension size in pixel \n");
    printf("vinfo.xres = %d \n", vinfo.xres);
    printf("vinfo.yres = %d \n", vinfo.yres);
    printf("\n");
    

    /* xres = 1920 */
    /* yres = 1080 */
    printf("Choose which line number you want color \n");
    scanf("%d", &user_line_number);
    printf("you choose line = %d \n", user_line_number);


    int x,y;
    
	for (x=0;x<vinfo.xres;x++)
		for (y=0;y<vinfo.yres;y++)
		{
			long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
			*((uint32_t*)(fbp + location)) = pixel_color(0x00,0x00,0x00, &vinfo);

            if( y == user_line_number ){
                for(int i = 0; i < vinfo.xres; i++){
                    *((uint32_t*)(fbp + location)) = pixel_color(0x00,0xFF,0x00, &vinfo);
                }                
            }
		}

	return 0;
}