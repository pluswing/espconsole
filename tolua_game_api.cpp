/*
** Lua binding: game_api
** Generated automatically by tolua++-1.0.92 on Thu Aug  1 09:08:51 2019.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "toluapp.h"

/* Exported function */
TOLUA_API int  tolua_game_api_open (lua_State* tolua_S);

#include "game_api.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"GameApi");
}

/* method: width of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_width00
static int tolua_game_api_GameApi_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   int tolua_ret = (int)  self->width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: height of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_height00
static int tolua_game_api_GameApi_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'", NULL);
#endif
  {
   int tolua_ret = (int)  self->height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFPS of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_setFPS00
static int tolua_game_api_GameApi_setFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int fps = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFPS'", NULL);
#endif
  {
   self->setFPS(fps);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFPS of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_getFPS00
static int tolua_game_api_GameApi_getFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFPS'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFPS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showFPS of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_showFPS00
static int tolua_game_api_GameApi_showFPS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int color = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showFPS'", NULL);
#endif
  {
   self->showFPS(x,y,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showFPS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cls of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_cls00
static int tolua_game_api_GameApi_cls00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int color = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cls'", NULL);
#endif
  {
   self->cls(color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cls'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pix of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_pix00
static int tolua_game_api_GameApi_pix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int color = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pix'", NULL);
#endif
  {
   self->pix(x,y,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: line of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_line00
static int tolua_game_api_GameApi_line00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,5,0));
  int color = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'line'", NULL);
#endif
  {
   self->line(x1,y1,x2,y2,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'line'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rect of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_rect00
static int tolua_game_api_GameApi_rect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  int color = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rect'", NULL);
#endif
  {
   self->rect(x,y,w,h,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rectb of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_rectb00
static int tolua_game_api_GameApi_rectb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  int color = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rectb'", NULL);
#endif
  {
   self->rectb(x,y,w,h,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rectb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: circ of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_circ00
static int tolua_game_api_GameApi_circ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int r = ((int)  tolua_tonumber(tolua_S,4,0));
  int color = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'circ'", NULL);
#endif
  {
   self->circ(x,y,r,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'circ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: circb of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_circb00
static int tolua_game_api_GameApi_circb00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int r = ((int)  tolua_tonumber(tolua_S,4,0));
  int color = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'circb'", NULL);
#endif
  {
   self->circb(x,y,r,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'circb'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: text of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_text00
static int tolua_game_api_GameApi_text00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* s = ((const char*)  tolua_tostring(tolua_S,4,0));
  int color = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'text'", NULL);
#endif
  {
   self->text(x,y,s,color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'text'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: color of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_color00
static int tolua_game_api_GameApi_color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int r = ((int)  tolua_tonumber(tolua_S,2,0));
  int g = ((int)  tolua_tonumber(tolua_S,3,0));
  int b = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'color'", NULL);
#endif
  {
   int tolua_ret = (int)  self->color(r,g,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: btn of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_btn00
static int tolua_game_api_GameApi_btn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'btn'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->btn(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'btn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: btnp of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_btnp00
static int tolua_game_api_GameApi_btnp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'btnp'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->btnp(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'btnp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: btnr of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_btnr00
static int tolua_game_api_GameApi_btnr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  int button = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'btnr'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->btnr(button);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'btnr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: analogY of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_analogY00
static int tolua_game_api_GameApi_analogY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'analogY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->analogY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'analogY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: analogX of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_analogX00
static int tolua_game_api_GameApi_analogX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'analogX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->analogX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'analogX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: print of class  GameApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GameApi_print00
static int tolua_game_api_GameApi_print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameApi",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameApi* self = (GameApi*)  tolua_tousertype(tolua_S,1,0);
  const char* message = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'print'", NULL);
#endif
  {
   self->print(message);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetApi */
#ifndef TOLUA_DISABLE_tolua_game_api_GetApi00
static int tolua_game_api_GetApi00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GameApi* tolua_ret = (GameApi*)  GetApi();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameApi");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetApi'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_game_api_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"BTN_A_PIN",BTN_A_PIN);
  tolua_constant(tolua_S,"BTN_B_PIN",BTN_B_PIN);
  tolua_constant(tolua_S,"ANALOG_Y_PIN",ANALOG_Y_PIN);
  tolua_constant(tolua_S,"ANALOG_X_PIN",ANALOG_X_PIN);
  tolua_constant(tolua_S,"ANALOG_MAX",ANALOG_MAX);
  tolua_constant(tolua_S,"ANALOG_THRETHOLD",ANALOG_THRETHOLD);
  tolua_constant(tolua_S,"ANALOG_RANGE",ANALOG_RANGE);
  tolua_constant(tolua_S,"REVERSE_ANALOG_X",REVERSE_ANALOG_X);
  tolua_constant(tolua_S,"REVERSE_ANALOG_Y",REVERSE_ANALOG_Y);
  tolua_constant(tolua_S,"DISPLAY_CS",DISPLAY_CS);
  tolua_constant(tolua_S,"DISPLAY_RST",DISPLAY_RST);
  tolua_constant(tolua_S,"DISPLAY_DC",DISPLAY_DC);
  tolua_constant(tolua_S,"COLOR_WHITE",COLOR_WHITE);
  tolua_constant(tolua_S,"COLOR_BLACK",COLOR_BLACK);
  tolua_constant(tolua_S,"COLOR_RED",COLOR_RED);
  tolua_constant(tolua_S,"COLOR_BLUE",COLOR_BLUE);
  tolua_constant(tolua_S,"COLOR_GREEN",COLOR_GREEN);
  tolua_constant(tolua_S,"COLOR_YELLOW",COLOR_YELLOW);
  tolua_constant(tolua_S,"COLOR_MAGENTA",COLOR_MAGENTA);
  tolua_constant(tolua_S,"COLOR_CYAN",COLOR_CYAN);
  tolua_constant(tolua_S,"BTN_A",BTN_A);
  tolua_constant(tolua_S,"BTN_B",BTN_B);
  tolua_constant(tolua_S,"BTN_UP",BTN_UP);
  tolua_constant(tolua_S,"BTN_DOWN",BTN_DOWN);
  tolua_constant(tolua_S,"BTN_LEFT",BTN_LEFT);
  tolua_constant(tolua_S,"BTN_RIGHT",BTN_RIGHT);
  tolua_cclass(tolua_S,"GameApi","GameApi","",NULL);
  tolua_beginmodule(tolua_S,"GameApi");
   tolua_function(tolua_S,"width",tolua_game_api_GameApi_width00);
   tolua_function(tolua_S,"height",tolua_game_api_GameApi_height00);
   tolua_function(tolua_S,"setFPS",tolua_game_api_GameApi_setFPS00);
   tolua_function(tolua_S,"getFPS",tolua_game_api_GameApi_getFPS00);
   tolua_function(tolua_S,"showFPS",tolua_game_api_GameApi_showFPS00);
   tolua_function(tolua_S,"cls",tolua_game_api_GameApi_cls00);
   tolua_function(tolua_S,"pix",tolua_game_api_GameApi_pix00);
   tolua_function(tolua_S,"line",tolua_game_api_GameApi_line00);
   tolua_function(tolua_S,"rect",tolua_game_api_GameApi_rect00);
   tolua_function(tolua_S,"rectb",tolua_game_api_GameApi_rectb00);
   tolua_function(tolua_S,"circ",tolua_game_api_GameApi_circ00);
   tolua_function(tolua_S,"circb",tolua_game_api_GameApi_circb00);
   tolua_function(tolua_S,"text",tolua_game_api_GameApi_text00);
   tolua_function(tolua_S,"color",tolua_game_api_GameApi_color00);
   tolua_function(tolua_S,"btn",tolua_game_api_GameApi_btn00);
   tolua_function(tolua_S,"btnp",tolua_game_api_GameApi_btnp00);
   tolua_function(tolua_S,"btnr",tolua_game_api_GameApi_btnr00);
   tolua_function(tolua_S,"analogY",tolua_game_api_GameApi_analogY00);
   tolua_function(tolua_S,"analogX",tolua_game_api_GameApi_analogX00);
   tolua_function(tolua_S,"print",tolua_game_api_GameApi_print00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"GetApi",tolua_game_api_GetApi00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_game_api (lua_State* tolua_S) {
 return tolua_game_api_open(tolua_S);
};
#endif

