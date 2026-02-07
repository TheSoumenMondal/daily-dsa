package array;
import java.util.ArrayList;

public class SortedArrayUnion {

    public static ArrayList<Integer> GetSortedArrayUnion(ArrayList<Integer> arr , ArrayList<Integer> brr){
        ArrayList<Integer> UnionArrayList = new ArrayList<>();
        int i =0;
        int j = 0;
        int n = arr.size();
        int m = brr.size();
        while(i<n && j<m){
            if(arr.get(i) < brr.get(j)){
                if(UnionArrayList.size() == 0 || UnionArrayList.get(UnionArrayList.size() - 1) != arr.get(i)){
                    UnionArrayList.add(arr.get(i));
                }
                i++;
            }else if(brr.get(j) < arr.get(i)){
                if(UnionArrayList.size() == 0 || UnionArrayList.get(UnionArrayList.size() - 1) != brr.get(j)){
                    UnionArrayList.add(brr.get(j));
                }
                j++;
            }else{
                if(UnionArrayList.size() == 0 || UnionArrayList.get(UnionArrayList.size() - 1) != brr.get(j)){
                    UnionArrayList.add(brr.get(j));
                }
                j++;
            }
        }

        while(i<n){
            if(UnionArrayList.size() == 0 || UnionArrayList.get(UnionArrayList.size()-1) != arr.get(i)){
                UnionArrayList.add(arr.get(i));
            }
            i++;
        }

        while(j<m){
            if(UnionArrayList.size() == 0 || UnionArrayList.get(UnionArrayList.size() - 1) != brr.get(j)){
                UnionArrayList.add(brr.get(j));
            }
            j++;
        }

        return UnionArrayList;
    }

    public static void printArrayList(ArrayList<Integer> arr){
        for(int num : arr){
            System.out.print(num + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(12);
        arr.add(14);
        arr.add(14);
        arr.add(15);
        arr.add(16);
        arr.add(17);
        ArrayList<Integer> brr = new ArrayList<>();
        brr.add(12);
        brr.add(14);
        brr.add(15);
        brr.add(16);
        brr.add(16);
        brr.add(19);
        ArrayList<Integer> unionArray = GetSortedArrayUnion(arr,brr);
        printArrayList(unionArray);
    }
}
