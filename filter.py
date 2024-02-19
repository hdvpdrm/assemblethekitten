

with open("vanilla.nki","r") as f:
    data = f.read()
    data = data.split("\n")
    s = [x for x in data if len(x) < 43]
    print(len(s))
    with open("2.nki","w") as d:
        for st in s:
            d.write(st+"\n")
