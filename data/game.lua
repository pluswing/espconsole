require("strict")

local api = GetApi()

api:setFPS(30)

local ball = {
    x = 0,
    y = 0,
    mx = 1,
    my = 1,
    size = 10,
}

local bar = {
    x = 0,
    y = api:height() - 10,
    w = 20,
}

local gameover = false

function update()
    if gameover then
        return
    end

    ball.x = ball.x + ball.mx
    ball.y = ball.y + ball.my

    if ball.x < 0 then
        ball.mx = 1
    end

    if ball.x > api:width() - ball.size then
        ball.mx = -1
    end

    if ball.y < 0 then
        ball.my = 1
    end

    if ball.y + ball.size > bar.y then
        if bar.x > ball.x + ball.size then
            gameover = true
            return
        end
        if bar.x + bar.w < ball.x then
            gameover = true
            return
        end
        ball.my = -1
    end

    if api:btn(BTN_LEFT) then
        bar.x = bar.x - 3
        if bar.x < 0 then
            bar.x = 0
        end
    end
    if api:btn(BTN_RIGHT) then
        bar.x = bar.x + 3
        if bar.x > api:width() - bar.w then
            bar.x = api:width() - bar.w
        end
    end
end

function draw()
    api:cls(COLOR_BLACK)

    api:rect(ball.x, ball.y, ball.size, ball.size, COLOR_GREEN)
    api:line(bar.x, bar.y, bar.x+bar.w, bar.y, COLOR_WHITE)

    if gameover then
        api:text(40, api:height()/2, "GAME OVER!", COLOR_RED)
    end
end
