using System;

namespace Bubble_Sort
{
    class Sorting
    {
        static void Main(string[] args)
        {
            // Tamanho do array
            int tamanho = 10;

            // Criar um array de inteiros aleatórios
            int[] numeros = new int[tamanho];
            Random random = new Random();
            for (int i = 0; i < tamanho; i++)
            {
                numeros[i] = random.Next(100);
            }

            // Ordenação por bolha
            for (int i = 0; i < tamanho - 1; i++)
            {
                for (int j = 0; j < tamanho - i - 1; j++)
                {
                    if (numeros[j] > numeros[j + 1])
                    {
                        // Trocar os elementos
                        int temp = numeros[j];
                        numeros[j] = numeros[j + 1];
                        numeros[j + 1] = temp;
                    }
                }
            }

            // Imprimir o array ordenado
            Console.WriteLine("Array ordenado:");
            foreach (int numero in numeros)
            {
                Console.Write(numero + " ");
            }
        }
    }
}