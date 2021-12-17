#include "dct.h"
#include "Ycbcr.h"
#include "quantification.h"
#include "stb_image.h"
#include "stb_image_write.h"



int main()
{
    int width, height, channels;

    unsigned char* img = stbi_load("LevelMap.png", &width, &height, &channels, 0);
    if (img == NULL) {
        printf("Error in loading the image\n");
        exit(1);    
    }

    printf("-------------------Image---------------------\n");
    printf("width: %d\n", width);
    printf("height: %d\n", height);
    printf("channels: %d\n", channels);
    printf("---------------------------------------\n");
    
    struct RGB data = { 82, 0, 87 };
    struct YCbCr value = RGBToYCbCr(data);

    printYCbCr(value);

    int matrix[m][n] = { { -76, -73, -67, -62, -58, -67, -64, -55 },
                         { -65, -69, -73, -38, -19, -43, -59, -56 },
                         { -66, -69, -60, -15, 16, -24, -62, -55 },
                         { -65, -70, -57, -6, 26, -22, -58, -59 },
                         { -61, -67, -60, -24, -2, -40, -60, -58 },
                         { -49, -63, -68, -58, -51, -60, -70, -53 },
                         { -43, -57, -64, -69, -73, -67, -63, -45 },
                         { -41, -49, -59, -60, -63, -52, -50, -34 } };

    float dctMatrix[m][n];

    dctTransform(matrix, dctMatrix);

    //printMatrix(dctMatrix);

    quantify(dctMatrix);

    stbi_write_png("LevelMap1.png", width, height, channels, img, width * channels);

    stbi_image_free(img);

    return 0;
}