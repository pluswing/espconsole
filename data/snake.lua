local api = GetApi()

local list = {
    {x=0, y=0},
}
local direction = 1
local length = 5
local speed = 60
local addSpeed = 10
local frameCount = 0
local moveCount = 0

function update()

    if api:btnp(BTN_UP) ~= 0 then
        direction = 0
    elseif api:btnp(BTN_LEFT) ~= 0 then
        direction = 3
    elseif api:btnp(BTN_RIGHT) ~= 0 then
        direction = 1
    elseif api:btnp(BTN_DOWN) ~= 0 then
        direction = 2
    end

    frameCount = frameCount + 1
    if frameCount < speed then
        return
    end
    frameCount = 0

    local top = list[1]

    local x = top["x"]
    local y = top["y"]

    if direction == 1 then
        x = x + 1
    elseif direction == 2 then
        y = y + 1
    elseif direction == 3 then
        x = x - 1
    else
        y = y - 1
    end
    table.insert(list, 1, {x=x, y=y})
    moveCount = moveCount + 1
    if moveCount > addSpeed then
        length = length + 1
        moveCount = 0
        speed = speed - 1
        addSpeed = addSpeed - 1
    end
    if length < #list then
        table.remove(list)
    end
end

function draw()
    api:cls(COLOR_BLACK)
    api:text(0, 50, "" .. length .. ", " .. #list, COLOR_WHITE)
    for i = 1, #list do
        api:rect(list[i]["x"] * 10, list[i]["y"] *10, 10, 10, COLOR_GREEN)
    end
end
