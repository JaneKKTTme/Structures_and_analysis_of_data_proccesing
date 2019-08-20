package lb2_2;
public class Lb2_2 {
    private static Node test1() {
        Node tr = new Node(2, null, null);
        tr.add(7, tr);
        tr.add(5, tr);
        tr.add(6, tr);
        tr.add(3, tr);
        tr.add(8, tr);
        tr.add(4, tr);
        return tr;
    }

    public static void main(String[] args) {
        //Вариант 19
        BT.printNode(test1());
        int result = BT.lengthWay(test1(), 0) + BT.numbersChildren(test1(), 0);
        System.out.println("Number of tops, which have "
                + "equal height of under the tree or equal\nnumbers "
                + "of descendant in right and left under the tree: " 
                + result);
    }
}
