/*************************************************
 * Автор:    Хан Кирилл                          *
 * Задание:  Циклы с предусловием и постусловием *
 * Вариант:  26                                  *
 ************************************************/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  const double startTime = 200.0;
  const double transitionTime = 1000.0;
  const double finishTime = 5000.0;
  const double firstStep = 200.0;
  const double secondStep = 1000.0;

  double lambda1, lambda2, phi;
  double coefficient, t, p;
  int stepIndex;

  cout << "lambda1 (1/h) = ";
  cin >> lambda1;

  cout << "lambda2 (1/h) = ";
  cin >> lambda2;

  cout << "phi = ";
  cin >> phi;

  coefficient = lambda1 * phi / (lambda1 - 0.5 * lambda2);

  cout << "t (h) P (%)" << endl;

  stepIndex = 0;
  t = startTime;
  do {
    p = ((1.0 - coefficient) * exp(-2.0 * lambda1 * t) +
        coefficient * exp(-lambda2 * t)) * 100.0;
    cout << t << " " << p << endl;
    ++stepIndex;
    t = startTime + stepIndex * firstStep;
  } while (t <= transitionTime);

  stepIndex = 1;
  t = transitionTime + stepIndex * secondStep;
  while (t <= finishTime) {
    p = ((1.0 - coefficient) * exp(-2.0 * lambda1 * t) +
        coefficient * exp(-lambda2 * t)) * 100.0;
    cout << t << " " << p << endl;
    ++stepIndex;
    t = transitionTime + stepIndex * secondStep;
  }

  return 0;
}
