local api = GetApi()

function update()
end

function draw()
    api:cls(COLOR_BLACK)
    api:circb(api:analogX() + 80, api:analogY() + 64, 20, COLOR_GREEN)
end
