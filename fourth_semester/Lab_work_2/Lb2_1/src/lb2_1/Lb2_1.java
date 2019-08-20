package lb2_1;
public class Lb2_1 {
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
        //Вариант 8
        BT.printNode(test1());
        int[] array = new int[7];
        array = BT.compareNumberOfRoot(test1(), array, 0);
        System.out.print("Numbers of tops, where difference between left and right under\nthe tree is one: ");
        for (int i = 0; i < 7 & array[i] != 0; i++)
            System.out.println(array[i] + " ");
    } 
}
