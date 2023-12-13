#ifndef CONFIG_HPP
#define CONFIG_HPP

#define PLATFORM_START_Z                 10000
#define PLATFORM_START             10, 10, PLATFORM_START_Z

//центр вего -500 )
#define CENTER_POINT_X                1145
#define CENTER_POINT_Y                950

//размер shadow bufera
#define LIGHT_SHADOW_X             2000
#define LIGHT_SHADOW_Y             2000

//коефы
#define SCALE_FACTOR            80
#define MOVE_FACTOR               50
#define ROTATE_COEF             3.14159265358979323846 / 8
#define SCALE_COEF             0.1

//colors
#define BLACK_COLOR            0, 0, 0
#define WHITE_COLOR             255, 255, 255

#define PLATFORM_COLOR             112, 229, 0
#define PLATFORM_SHADOW_COLOR      73, 149 , 0

//HOME
#define HOME_COLOR              229, 228, 183
#define HOME_SHADOW_COLOR         168, 151, 111

#define HOME_ROOF_COLOR         115, 23, 26
#define HOME_ROOF_SHADOW_COLOR    79, 7, 9

#define HOME_WINDOW_COLOR      118, 180, 217
#define HOME_WINDOW_SHADOW_COLOR 70, 138, 178

//TreE
#define TREE_LEAVES_COLOR      58, 87, 35
#define TREE_LEAVES_SHASOW_COLOR 31, 57, 11

#define TREE_TRUNK_COLOR        87, 67, 38
#define TREE_TRUNK_SHADOW_COLOR   57, 39, 12

//ROAD
#define ROAD_COLOR      27, 25, 43
#define ROAD_SHADOW_COLOR 21, 20, 31

//CAR
#define ROAD_STRIPE_COLOR       255, 253, 251
#define DARK_ROAD_STRIPE_COLOR  226, 224, 223

#define CAR_GREY_COLOR               130,126,128
#define CAR_GREY_SHADOW_COLOR          98,95,96

#define CAR_WHEELS_COLOR        78, 84, 92
#define CAR_WHEELS_SHADOW_COLOR   66, 71, 76

#define CAR_GLASS_COLOR         118, 180, 217
#define DARK_CAR_GLASS_COLOR    70, 138, 178

#define SIDEWALK_COLOR         168, 175, 185
#define SIDEWALK_SHADOW_COLOR    205, 211, 220

#define BORDER_COLOR         129, 129, 129
#define BORDER_SHADOW_COLOR    192, 192, 192


#define EPS 1e-3

#endif // CONFIG_HPP
