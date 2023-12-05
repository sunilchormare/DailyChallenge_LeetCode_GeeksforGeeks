class Solution {
    public String reformatDate(String date) {
    String[] months = new String[]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    Map<String, String> map = new HashMap<>();
    for (int i = 0; i < months.length; ++i) {
        map.put(months[i], (i + 1 < 10 ? "0" : "") + (i+1));    
    }
    String[] parts = date.split(" "); 
    String day = (parts[0].length() == 3 ? "0" : "") + parts[0].substring(0, parts[0].length() - 2);
    return parts[2] + "-" + map.get(parts[1]) + "-" + day;
    
}
}
