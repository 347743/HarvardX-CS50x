def cal_q(cents):
    return cents // 25


def cal_d(cents):
    return cents // 10


def cal_n(cents):
    return cents // 5


def cal_p(cents):
    return cents


def main():
    while True:
        try:
            dollars = float(input("Change owed: "))
            if dollars >= 0:
                break
        except ValueError:
            pass

    cents = round(dollars * 100)

    # Calculate coins
    q = cal_q(cents)
    cents -= q * 25

    d = cal_d(cents)
    cents -= d * 10

    n = cal_n(cents)
    cents -= n * 5

    p = cal_p(cents)
    cents -= p * 1
    # Total coins
    cash = q + d + n + p
    print(cash)


if __name__ == "__main__":
    main()
