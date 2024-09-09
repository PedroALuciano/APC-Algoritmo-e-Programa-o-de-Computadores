//Crie um programa que seja capaz de ler os dados e calcular o perímetro e a área das seguintes figuras geométricas: círculo, quadrado, retângulo e trapézio. O usuário deverá inicialmente informar qual a figura geométrica e, a partir de então, os programa deverá ler os dados da figura e calcular seu perímetro e área.
import java.util.Scanner;

public class CalculadoraGeometrica {

    // Método para calcular o perímetro e a área do círculo
    public static void calcularCirculo(double raio) {
        double perimetro = 2 * Math.PI * raio;
        double area = Math.PI * Math.pow(raio, 2);
        System.out.println("Perímetro: " + perimetro);
        System.out.println("Área: " + area);
    }

    // Método para calcular o perímetro e a área do quadrado
    public static void calcularQuadrado(double lado) {
        double perimetro = 4 * lado;
        double area = Math.pow(lado, 2);
        System.out.println("Perímetro: " + perimetro);
        System.out.println("Área: " + area);
    }

    // Método para calcular o perímetro e a área do retângulo
    public static void calcularRetangulo(double lado1, double lado2) {
        double perimetro = 2 * (lado1 + lado2);
        double area = lado1 * lado2;
        System.out.println("Perímetro: " + perimetro);
        System.out.println("Área: " + area);
    }

    // Método para calcular o perímetro e a área do trapézio
    public static void calcularTrapezio(double baseMaior, double baseMenor, double altura) {
        double perimetro = baseMaior + baseMenor + 2 * Math.sqrt(Math.pow(altura, 2) + Math.pow((baseMaior - baseMenor) / 2, 2));
        double area = altura * (baseMaior + baseMenor) / 2;
        System.out.println("Perímetro: " + perimetro);
        System.out.println("Área: " + area);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Qual a figura geométrica (círculo, quadrado, retângulo ou trapézio)? ");
        String figura = scanner.nextLine();
        switch (figura) {
            case "círculo":
                System.out.print("Digite o raio: ");
                double raio = scanner.nextDouble();
                calcularCirculo(raio);
                break;
            case "quadrado":
                System.out.print("Digite o lado: ");
                double lado = scanner.nextDouble();
                calcularQuadrado(lado);
                break;
            case "retângulo":
                System.out.print("Digite o primeiro lado: ");
                double lado1 = scanner.nextDouble();
                System.out.print("Digite o segundo lado: ");
                double lado2 = scanner.nextDouble();
                calcularRetangulo(lado1, lado2);
                break;
            case "trapézio":
                System.out.print("Digite a base maior: ");
                double baseMaior = scanner.nextDouble();
                System.out.print("Digite a base menor: ");
                double baseMenor = scanner.nextDouble();
                System.out.print("Digite a altura: ");
                double altura = scanner.nextDouble();
                calcularTrapezio(baseMaior, baseMenor, altura);
                break;
            default:
                System.out.println("Figura geométrica inválida.");
        }
        scanner.close();
    }
}
