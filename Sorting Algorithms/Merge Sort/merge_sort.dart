import 'dart:ffi';
import 'dart:math';

void merge_arrays(List<int> arrays, left, mid, right) {
  int i, j, k;
  int n1 = left + 1;
  int n2 = right - mid;
  List<int> L = List.filled(n1, 0);
  List<int> R = List.filled(n2, 0);

  for (i = 0; i < n1; i++) {
    L[i] = arrays[left + i];
  }

  for (j = 0; j < n2; j++) {
    R[j] = arrays[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arrays[k] = L[i];
      i++;
    } else {
      arrays[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arrays[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[],
  // if there are any
  while (j < n2) {
    arrays[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(List<int> array, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) ~/ 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    merge_arrays(array, left, middle, right);
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
  merge_sort(array, 0, array.length - 1);
  print('Array ordenado');
  imprime_array(array, array.length);
}
