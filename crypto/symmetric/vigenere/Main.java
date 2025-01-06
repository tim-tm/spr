public class Main {
    public static void main(String[] args) {
        String text = "HELLOWORLD";
        String key = "ABC";

        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            builder.append(key.charAt(i % key.length()));
        }
        String extended_key = builder.toString();

        StringBuilder cipher_builder = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char c = (char)(65 + ((text.charAt(i) + extended_key.charAt(i)) % 26));
            cipher_builder.append(c);
        }
        String cipher = cipher_builder.toString();
        System.out.println(cipher);

        StringBuilder msg_builder = new StringBuilder();
        for (int i = 0; i < cipher.length(); i++) {
            char c = (char)(65 + ((cipher.charAt(i) - extended_key.charAt(i)) % 26));
            msg_builder.append(c);
        }
        System.out.println(msg_builder.toString());
    }
}
