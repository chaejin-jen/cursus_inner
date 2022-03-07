71 results - 15 files

mlx_init_loop.m:
  3  
  4: #import <Cocoa/Cocoa.h>
  5: #import <OpenGL/gl3.h>
  6: #import <AppKit/NSOpenGLView.h>
  7  
  8: #include "mlx_int.h"
  9: #include "mlx_new_window.h"
  10  

mlx_int_str_to_wordtab.c:
  5  
  6: #include <stdlib.h>
  7: #include <string.h>
  8  

mlx_int.h:
  1  //
  2: // mlx_int.h for minilibx
  3  //

  5  //
  6: // include opengl needed before mlx_int.h
  7  //

mlx_mouse.m:
  1: #include	<stdio.h>
  2  
  3: #import <Cocoa/Cocoa.h>
  4: #import <OpenGL/gl3.h>
  5  
  6: #include	"mlx_int.h"
  7: #include	"mlx_new_window.h"
  8  

mlx_new_image.m:
   6  
   7: #import <Cocoa/Cocoa.h>
   8: #import <OpenGL/gl3.h>
   9  
  10: #include "mlx_int.h"
  11: #include "mlx_new_window.h"
  12  

mlx_new_window.h:
   1  //
   2: // mlx_int.h for minilibx
   3  //

   5  //
   6: // include opengl needed before mlx_int.h
   7  //
   8  
   9: #import <Cocoa/Cocoa.h>
  10: #import "mlx_int.h"
  11  

mlx_new_window.m:
    2  
    3: #import <Cocoa/Cocoa.h>
    4: #import <OpenGL/gl3.h>
    5: #import <AppKit/NSOpenGLView.h>
    6  
    7: #include <stdio.h>
    8: #include <math.h>
    9  
   10: #include "mlx_int.h"
   11: #include "mlx_new_window.h"
   12  

   76        size_x = rect.size.width;
   77:       size_y = rect.size.height;
   78      }

  378        size_x = rect.size.width;
  379:       size_y = rect.size.height;
  380  

mlx_opengl.h:
  2  **
  3: ** mlx_opengl.h 
  4  **
  5: ** public include, use it after mlx.h
  6  ** designed only for minilibx_macos

mlx_opengl.m:
   2  
   3: #import <Cocoa/Cocoa.h>
   4: #import <OpenGL/gl3.h>
   5: #import <AppKit/NSOpenGLView.h>
   6  
   7: #include <stdio.h>
   8  
   9: #include "mlx_int.h"
  10: #include "mlx_new_window.h"
  11  

mlx_png.c:
    2  
    3: #include <stdlib.h>
    4: #include <stdio.h>
    5: #include <sys/mman.h>
    6: #include <unistd.h>
    7: #include <fcntl.h>
    8: #include <err.h>
    9: #include <string.h>
   10: #include <arpa/inet.h>
   11  
   12: #include "zlib.h"
   13  
   14: #include <OpenGL/gl3.h>
   15: #include	"mlx_int.h"
   16  

  372      }
  373:   if (!(img = mlx_new_image(xvar, pi.width, pi.height)))
  374      {

mlx_shaders.c:
  2  
  3: #include <stdlib.h>
  4: #include <stdio.h>
  5: #include <string.h>
  6: #include <OpenGL/gl3.h>
  7: #include "mlx_int.h"
  8  

mlx_xpm.c:
   3  
   4: #include <OpenGL/gl3.h>
   5: #include <stdlib.h>
   6: #include <stdio.h>
   7: #include <sys/mman.h>
   8: #include <unistd.h>
   9: #include <fcntl.h>
  10: #include <string.h>
  11: #include	"mlx_int.h"
  12  

mlx.h:
    1  /*
    2: ** mlx.h for MinilibX in 
    3  ** 

  133  **  generic hook system for all events, and minilibX functions that
  134: **    can be hooked. Some macro and defines from X11/X.h are needed here.
  135  */
