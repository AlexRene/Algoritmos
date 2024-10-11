import 'dart:math';

int partition(List<int> array, int menor, int pivo) {
  int pivot = array[pivo];

  int i = menor - 1;

  for (int j = menor; j <= pivo; j++) {
    if (array[j] < pivot) {
      i++;
      int aux = array[i];
      array[i] = array[j];
      array[j] = aux;
    }
  }

  int aux2 = array[i + 1];
  array[i + 1] = array[pivo];
  array[pivo] = aux2;

  return i + 1;
}

void quick_sort(List<int> array, int menor, int pivo) {
  if (menor < pivo) {
    int partition_index = partition(array, menor, pivo);

    quick_sort(array, menor, partition_index - 1);
    quick_sort(array, partition_index + 1, pivo);
  }
}

void imprime_array(List<int> Array, int tamanho_array) {
  for (int i = 0; i < tamanho_array; i++) {
    print(Array[i]);
  }
}

void main() {
  const TAM = 10;
  List<int> array = [];
  Random random = new Random();

  for (int i = 0; i < TAM; i++) {
    array.add(random.nextInt(100 - 1 + 1) + 1);
  }

  imprime_array(array, array.length);
  quick_sort(array, 0, array.length - 1);
  print('Array ordenado');
  imprime_array(array, array.length);
}
