def main():
    inp = input("Enter date: ")
    spl = inp.split("/")
    intMonth = int(spl[0])
    dateConvert(intMonth)
    print(" " + spl[1] + ", " + spl[2])


def dateConvert(intMonth):
    months = ['January','February','March','April','May','June','July','August','September','October','November','December']
    month = months[intMonth - 1];
    print(month, end = '')
