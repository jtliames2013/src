http://blog.csdn.net/linhuanmars/article/details/23071455

这道题是LeetCode中AC率最低的题目，确实是比较难。一方面是因为对时间有比较严格的要求（容易超时），另一方面是它有很多细节需要实现。思路上和Word Ladder是比较类似的，但是因为是要求出所有路径，仅仅保存路径长度是不够的，而且这里还有更多的问题，那就是为了得到所有路径，不是每个结点访问一次就可以标记为visited了，因为有些访问过的结点也会是别的路径上的结点，所以访问的集合要进行回溯（也就是标记回未访问）。所以时间上不再是一次广度优先搜索的复杂度了，取决于结果路径的数量。同样空间上也是相当高的复杂度，因为我们要保存过程中满足的中间路径到某个数据结构中，以便最后可以获取路径，这里我们维护一个HashMap，把一个结点前驱结点都进行保存。
在LeetCode中用Java实现上述算法非常容易超时。为了提高算法效率，需要注意一下两点：
1）在替换String的某一位的字符时，先转换成char数组再操作；
2）如果按照正常的方法从start找end，然后根据这个来构造路径，代价会比较高，因为保存前驱结点容易，而保存后驱结点则比较困难。所以我们在广度优先搜索时反过来先从end找start，最后再根据生成的前驱结点映射从start往end构造路径，这样算法效率会有明显提高。

class StringWithLevel {  
   String str;  
   int level;  
   public StringWithLevel(String str, int level) {  
      this.str = str;  
      this.level = level;  
   }  
}  
public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict) {  
   ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();  
   HashSet<String> unvisitedSet = new HashSet<String>();  
   unvisitedSet.addAll(dict);  
   unvisitedSet.add(start);  
   unvisitedSet.remove(end);  
   Map<String, List<String>> nextMap = new HashMap<String, List<String>>();  
   for (String e : unvisitedSet) {  
      nextMap.put(e, new ArrayList<String>());  
   }  
   LinkedList<StringWithLevel> queue = new LinkedList<StringWithLevel>();  
   queue.add(new StringWithLevel(end, 0));  
   boolean found = false;  
   int finalLevel = Integer.MAX_VALUE;  
   int curLevel = 0;  
   int preLevel = 0;  
   HashSet<String> visitedCurLevel = new HashSet<String>();  
   while (!queue.isEmpty()) {  
      StringWithLevel cur = queue.poll();  
      String curStr = cur.str;  
      curLevel = cur.level;  
      if(found && curLevel > finalLevel) {  
         break;  
      }  
      if (curLevel > preLevel) {  
         unvisitedSet.removeAll(visitedCurLevel);  
      }  
      preLevel = curLevel;  
      char[] curStrCharArray = curStr.toCharArray();  
      for (int i = 0; i < curStr.length(); ++i) {  
         char originalChar = curStrCharArray[i];  
         boolean foundCurCycle = false;  
         for (char c = 'a'; c <= 'z'; ++c) {  
            curStrCharArray[i] = c;  
            String newStr = new String(curStrCharArray);  
            if(c != originalChar && unvisitedSet.contains(newStr)) {  
               nextMap.get(newStr).add(curStr);  
               if(newStr.equals(start)) {  
                  found = true;  
                  finalLevel = curLevel;  
                  foundCurCycle = true;  
                  break;  
               }  
               if(visitedCurLevel.add(newStr)) {  
                  queue.add(new StringWithLevel(newStr, curLevel + 1));  
               }  
            }  
         }  
         if(foundCurCycle) {  
            break;  
         }  
         curStrCharArray[i] = originalChar;  
     }  
   }  
   if(found) {  
       ArrayList<String> list = new ArrayList<String>();  
       list.add(start);  
       getPaths(start, end, list, finalLevel + 1, nextMap, res);  
   }  
   return res;  
}  
private void getPaths(String cur, String end, ArrayList<String> list, int level, Map<String, List<String>> nextMap, ArrayList<ArrayList<String>> res) {  
   if(cur.equals(end)){  
      res.add(new ArrayList<String>(list));  
   }  
   else if(level > 0){  
      List<String> parentsSet = nextMap.get(cur);  
      for (String parent : parentsSet) {  
         list.add(parent);  
         getPaths(parent, end, list, level - 1, nextMap, res);  
         list.remove(list.size() - 1);  
      }  
   }  
}  

