from sortedcontainers import SortedSet

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.c_f = defaultdict(SortedSet)
        self.cuisine = {}
        self.rating = {}

        for i in range(len(foods)):
            self.c_f[cuisines[i]].add((-ratings[i], foods[i]))
            self.cuisine[foods[i]] = cuisines[i]
            self.rating[foods[i]] = ratings[i]        

    def changeRating(self, food: str, newRating: int) -> None:
        c = self.cuisine[food]
        r = self.rating[food]

        self.c_f[c].remove((-r, food))
        self.c_f[c].add((-newRating, food))
        self.rating[food] = newRating
        

    def highestRated(self, cuisine: str) -> str:
        return self.c_f[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)