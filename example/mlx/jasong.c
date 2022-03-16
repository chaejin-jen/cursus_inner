#include  "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers/gl3.h"
// #include "../../so_long/lib/mlx/mlx_int.h"
#include <mlx.h>
#include <stdio.h>

typedef struct	mlx_img_list_s
{
  int			width;
  int			height;
  char			*buffer;
  GLfloat		vertexes[8];
  struct mlx_img_list_s	*next;
} mlx_img_list_t;

int main(void)
{
    mlx_img_list_t img;

    img.width = 1;
    img.height = 1;
    printf("width : %d height : %d\n", img.width, img.height);
    return (0);
}