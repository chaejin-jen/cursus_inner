#import <Foundation/Foundation.h>

static NSLock * lock;

int main( void )
{
    @autoreleasepool
    {
        lock = [ NSLock new ];

        for( int i = 0; i < 10000; i++ )
        {
            [ NSThread detachNewThreadWithBlock: ^( void )
                {
                    [ lock lock ];

                    NSLog( @"Thread %i", i );

                    [ lock unlock ];

                    while( 1 )
                    {
                        [ NSThread sleepForTimeInterval: 1 ];
                    }
                }
            ];
        }

        while( 1 )
        {
            [ NSThread sleepForTimeInterval: 1 ];
        }
    }

    return 0;
}
