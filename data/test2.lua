local api = GetApi()
local current = 1
local palette = {
    COLOR_WHITE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_CYAN,
    COLOR_MAGENTA,
    COLOR_YELLOW,
}

function update()
    if api:btnp(BTN_A) ~= 0 then
        current = current + 1
    end
    if current >= #palette then
        current = 0
    end
end

function draw()
    api:cls(COLOR_BLACK)
    api:circb(api:analogX() + 80, api:analogY() + 64, 20, palette[current])
end
