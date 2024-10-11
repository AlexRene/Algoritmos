import 'dart:math';

void main() {
  const TAM = 10;
  List<int> array = [TAM];

  Random random = new Random();
  for (int i = 0; i < TAM - 1; i++) {
    array.add(random.nextInt(100 - 1 + 1) + 1);
  }

  for (int i = 1; i < TAM; i++) {
    int chave = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > chave) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = chave;
  }

  print(array);
}
