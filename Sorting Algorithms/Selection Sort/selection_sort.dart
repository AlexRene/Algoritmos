import 'dart:math';

void main() {
  List<int> array = [];
  const TAM = 10;

  Random random = new Random();
  for (int i = 0; i < TAM; i++) {
    array.add(random.nextInt(100 - 1 + 1) + 1);
  }

  print(array);

  for (int i = 0; i < TAM - 1; i++) {
    int atual_menor_valor = i;
    for (int j = i + 1; j < TAM; j++) {
      if (array[j] < array[atual_menor_valor]) {
        atual_menor_valor = j;
      }
      int aux = array[atual_menor_valor];
      array[atual_menor_valor] = array[i];
      array[i] = aux;
    }
  }

  print(array);
}
