-- 変数定義
local hoge = 1
local fuga = "a"

--[[
    複数行コメント

]]

-- 四則演算
hoge + 1
hoge - 1
hoge / 1
hoge * 10

hoge = hoge + 1
-- hoge += 1 NG!

-- 文字列結合
fuga .. "ccc"

-- テーブル
local arr = {
    3, 4, 5,
}

table.insert(arr, 7)
table.remove(arr)

local dict = {
    x = 10,
    y = 20,
}

dict["z"] = 30

-- テーブル参照
local v = arr[1] -- 3
local d = dict.z -- 30

-- if

if x == 1 then
    x = 10
elseif x == 2 then
    x = 15
else
    x = 20
end

if x == 1 then
elseif d ~= 10 then
end

-- for
for i=1, 10 do
    -- i = 1,,,,,10
end

-- for テーブル
for i, v in ipairs(arr) do
    -- 1, 3
    -- 2, 4
    -- 3, 5
end


for k, v in pairs(dict) do
    -- x, 10
    -- y, 20
end

tableLength = #arr
for i=1, tableLength do
    arr[i]
end


-- 関数定義
function func01(a, b)
    -- ...
end

-- 関数呼び出し
func01(10, 20)

-- テーブルに関数
local obj = {
    a = 10,
    hoge = function(this, b)
        this.a + b
    end
}

obj.a
obj:hoge(10)

-- obj.hoge(obj)
