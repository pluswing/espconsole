local api = GetApi()

local ball = {
    x=0,
    y=0,
    px=0,
    py=0,
    mx=0,
    my=0
}

local stage = {
    {9, 9, 9, 9, 9, 9},
    {9, 3, 0, 2, 0, 9},
    {9, 0, 0, 2, 0, 9},
    {9, 0, 0, 2, 0, 9},
    {9, 0, 0, 0, 0, 9},
    {9, 9, 9, 9, 9, 9},
}

local clear = false

function initBallPos()
    for y, l in ipairs(stage) do
        for x, v in ipairs(l) do
            if v == 3 then
                ball.x = (x - 1)
                ball.y = (y - 1)
                ball.px = ball.x * 10
                ball.py = ball.y * 10
            end
        end
    end
end

initBallPos()

function update()
    if ball.mx ~= 0 then
        ball.px = ball.px + ball.mx
    end

    if ball.my ~= 0 then
        ball.py = ball.py + ball.my
    end

    if (ball.px % 10) == 0 then
        ball.x = (ball.px / 10) + 1
    end
    if (ball.py % 10) == 0 then
        ball.y = (ball.py / 10) + 1
    end

    if stage[ball.y + ball.my][ball.x + ball.mx] > 1 then
        ball.mx = 0
        ball.my = 0
        ball.px = (ball.x - 1) * 10
        ball.py = (ball.y - 1) * 10
    else
        stage[ball.y][ball.x] = 1
    end

    if ball.mx ~= 0 or ball.my ~= 0 then
        return
    end

    if api:btn(BTN_UP) then
        ball.my = -1
        return
    end
    if api:btn(BTN_DOWN) then
        ball.my = 1
        return
    end
    if api:btn(BTN_LEFT) then
        ball.mx = -1
        return
    end
    if api:btn(BTN_RIGHT) then
        ball.mx = 1
        return
    end
end

function draw()
    api:cls(COLOR_BLACK)
    local zero = false
    for y, l in ipairs(stage) do
        for x, v in ipairs(l) do
            local px = (x - 1) * 10
            local py = (y - 1) * 10
            if v == 2 then
                api:rect(px, py, 10, 10, COLOR_RED)
            end
            if v == 1 or v == 3 then
                api:rect(px, py, 10, 10, COLOR_BLUE)
            end
            if v == 9 then
                api:rect(px, py, 10, 10, COLOR_RED)
            end
            if v == 0 then
                zero = true
            end
        end
    end

    if clear then
        api:text(40, 40, "CLEAR!", COLOR_WHITE)
    else
        api:circb(ball.px + 4, ball.py + 4, 5, COLOR_MAGENTA)
    end

    if not zero then
        clear = true
    end
end
