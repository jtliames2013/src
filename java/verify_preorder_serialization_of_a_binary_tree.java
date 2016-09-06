public class Solution {
    public boolean isValidSerialization(String preorder) {
        List<String> stack=new ArrayList<String>();
        String[] nodes = preorder.split(",");
        
        for (int i=0; i<nodes.length; i++) {
            stack.add(nodes[i]);
            while (stack.size()>=3) {
                if (stack.get(stack.size()-1).equals("#") && 
                    stack.get(stack.size()-2).equals("#")) {
                    if (stack.get(stack.size()-3).equals("#")) return false;
                    else {
                        stack.subList(stack.size()-3, stack.size()).clear();
                        stack.add("#");
                    }
                } else {
                    break;
                }
            }
        }
        
        if (stack.size()==1 && stack.get(0).equals("#")) return true;
        else return false;
    }
}
