import 'dart:math';

void main() {
  List<int> array = [];
  const TAM = 10;

  Random random = Random();
  for (int i = 0; i <= 10; i++) {
    array.add(random.nextInt(100 - 1 + 1) + 1);
  }

  for (int i = 0; i <= TAM - 1; i++) {
    for (int j = 0; j <= TAM - 1; j++) {
      if (array[j] > array[j + 1]) {
        int aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
      }
    }
  }

  print(array);
}
