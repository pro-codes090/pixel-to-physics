#include <stdio.h>

int main(void)
{
    const int width = 640;
    const int height = 640;
    FILE *file = fopen("outputs/week01-solid.ppm", "w");
    if (file == NULL) {
        perror("outputs/week01-solid.ppm");
        return 1;
    }

    const char * param1 = "128 255 64\n" ;
    const char * param2 = "64 255 128\n" ;
    
    const char *param = param1 ;

    /* P3 means plain-text RGB; header is magic, dimensions, max channel. */
    fprintf(file, "P3\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; ++y) {
        if (y %2 == 0)
        {
            param = param1 ;
        }
        else{
            param = param2 ;
            
        }
        
        for (int x = 0; x < width; ++x) {
            (void)x;
            fprintf(file,"%s" ,param);
        }
    }

    if (fclose(file) != 0) {
        perror("fclose");
        return 1;
    }
    return 0;
}