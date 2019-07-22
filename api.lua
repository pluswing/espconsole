-- INPUT
btn(BTN_A)
btnp(BTN_A)
btnr(BTN_A)

stick(STICK_X)
stick(STICK_Y)

-- Graphics
cls(color)
pix(x, y, color)
line(x1, y1, x2, y2, color)
rect(x, y, w, h, color) -- 矩形（塗りつぶし）
rectb(x, y, w, h, color) -- 輪郭線
circ(x, y, r, color)
circb(x, y, r, color)
text(x, y, s, color)

-- TODO bitmap

-- Audio
music(msc)
play_pos(ch)
play(ch, snd, loop)
playm(msc, loop)
stop(ch)

...
