local api = GetApi()

local press = ""

function update()
    press = ""
    if api:btn(BTN_A) ~= 0 then
        press = press .. "A "
    else
        press = press .. "  "
    end

    if api:btn(BTN_B) ~= 0 then
        press = press .. "B "
    else
        press = press .. "  "
    end

    if api:btn(BTN_UP) ~= 0 then
        press = press .. "U "
    else
        press = press .. "  "
    end

    if api:btn(BTN_DOWN) ~= 0 then
        press = press .. "D "
    else
        press = press .. "  "
    end

    if api:btn(BTN_LEFT) ~= 0 then
        press = press .. "L "
    else
        press = press .. "  "
    end

    if api:btn(BTN_RIGHT) ~= 0 then
        press = press .. "R "
    else
        press = press .. "  "
    end
end

function draw()
    api:cls(COLOR_BLACK)
    api:circb(api:analogX() + 80, api:analogY() + 64, 10, COLOR_GREEN)
    api:text(0, 0, press, COLOR_WHITE)
end
