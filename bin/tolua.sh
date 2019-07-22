bin/tolua++ -o tolua_game_api.cpp game_api.pkg
sed -i -e s/tolua++.h/toluapp.h/ tolua_game_api.cpp
