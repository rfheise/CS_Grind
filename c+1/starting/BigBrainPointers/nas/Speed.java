import java.util.ArrayList;


class Speed {

	public static void main(String[] args) {
		ArrayList<String> x = new ArrayList<String>();
		for(int i = 0; i < 1000000; i++) {
			x.add((char)('a' + i % 26) + "");
		}
		for (String str : x) {
			System.out.println(str);
		}

	}

}
