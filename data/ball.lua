local api = GetApi()


local ball = {
    x = 0,
    y = 0,
    mx = 0,
    my = 0,
}

local stage = {
    {2, 2, 2, 2, 2, 2},
    {2, 0, 0, 0, 0, 2},
    {2, 0, 3, 0, 0, 2},
    {2, 0, 0, 2, 0, 2},
    {2, 0, 0, 2, 0, 2},
    {2, 2, 2, 2, 2, 2},
}
local SIZE = 10
for y, line in ipairs(stage) do
    for x, v in ipairs(line) do
        if v == 3 then
            ball.x = x
            ball.y = y
        end
    end
end

local clear = false

function update()
    ball.x = ball.x + ball.mx
    ball.y = ball.y + ball.my

    if stage[ball.y][ball.x] == 2 then
        ball.x = ball.x - ball.mx
        ball.y = ball.y - ball.my
        ball.mx = 0
        ball.my = 0
    else
        stage[ball.y][ball.x] = 1
    end

    if ball.mx ~= 0 or ball.my ~= 0 then
        return
    end

    if api:btn(BTN_UP) then
        ball.my = -1
    end
    if api:btn(BTN_DOWN) then
        ball.my = 1
    end
    if api:btn(BTN_LEFT) then
        ball.mx = -1
    end
    if api:btn(BTN_RIGHT) then
        ball.mx = 1
    end
end

function draw()
    api:cls(COLOR_BLACK)

    local zero = false
    for y, line in ipairs(stage) do
        for x, v in ipairs(line) do
            if v == 1 then
                api:rect((x-1)*SIZE, (y-1)*SIZE, SIZE, SIZE, COLOR_RED)
            end
            if v == 2 then
                api:rect((x-1)*SIZE, (y-1)*SIZE, SIZE, SIZE, COLOR_BLUE)
            end
            if v == 0 then
                zero = true
            end
        end
    end

    if not zero then
        clear = true
    end
    if clear then
        api:text(20, 20, "CLEAR!", COLOR_WHITE)
    else
        api:circ((ball.x-1)*SIZE+SIZE/2, (ball.y-1)*SIZE+SIZE/2, SIZE/2, COLOR_GREEN)
    end
end
