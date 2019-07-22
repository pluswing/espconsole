local api = GetApi()

function update()
end

function draw()
    api:cls(COLOR_BLACK)
    api:rectb(api:analogX() + 80, api:analogY() + 64, 20, 20, COLOR_RED)
end
