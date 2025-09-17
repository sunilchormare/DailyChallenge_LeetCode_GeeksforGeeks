class Pair  implements Comparable<Pair> {
    String a;
    int b;
    Pair(String _aa, int _bb) {
        a = _aa;
        b = _bb;
    }
    
    public int compareTo(Pair c)
    {
        if (b != c.b) {
            return c.b - b;
        }
        else {
            return a.compareTo(c.a);
        }
    }
}
class FoodRatings {

    HashMap<String, Pair> fp = new HashMap<>();
    HashMap<String, TreeSet<Pair>> cp = new HashMap<>();
    
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for(int i=0;i<foods.length;i++) {
            
            fp.put(foods[i], new Pair(cuisines[i], ratings[i]));
            cp.putIfAbsent(cuisines[i], new TreeSet<>());
            cp.get(cuisines[i]).add(new Pair(foods[i], ratings[i]));
        }
    }
    
    public void changeRating(String food, int newRating) {
        
        Pair pp = fp.get(food);
        TreeSet<Pair> list = cp.get(pp.a);
        list.remove(new Pair(food, pp.b));
        
        fp.get(food).b = newRating;
        list.add(new Pair(food, newRating));
    }
    
    public String highestRated(String cuisine) {
        
        TreeSet<Pair> list = cp.get(cuisine);
        return list.iterator().next().a;
    }
}