#include "heap.hpp"

void Heap::SiftUp(int i) {
  while (a[i] < a[i / 2]) {
    std::swap(a[i], a[i / 2]);
    i /= 2;
  }
}

void Heap::SiftDown(int i) {
  while (2 * i < n) {
    int j = -1;
    if (a[2 * i] < a[i]) {
      j = 2 * i;
    }
    if (2 * i + 1 < n && a[2 * i + 1] < a[i] &&
        (j == -1 || a[2 * i] > a[2 * i + 1])) {
      j = 2 * i + 1;
    }
    if (j == -1)
      break;
    else {
      std::swap(a[i], a[j]);
      i = j;
    }
  }
}

int Heap::size() { return a.size(); }

int Heap::GetMin() { return a[0]; }

void Heap::Insert(int x) {
  a.push_back(x);
  n++;
  SiftUp(n - 1);
}

void Heap::extractMin() {
  a[0] = a[n];
  a.erase(a.begin() + n - 1);
  n--;
  SiftDown(0);
}

std::pair<int, std::vector<int>> Heap_exe(int n, int k, std::vector<int> a) {
  Heap useful_elements;
  std::map<int, int> indx;

  std::vector<int> ans(n, 0);

  long long i = 0;
  long long ans0 = 0;
  long long j = 0;

  while (j < n) {
    while (j - i < k && j < n) {
      if (a[j] < a[i]) {
        indx[a[j]] = j;
        useful_elements.Insert(a[j]);
        break;
      }

      if (i != j) {
        indx[a[j]] = j;
        useful_elements.Insert(a[j]);
      }

      ans0 += a[i];
      ans[i]++;

      j++;
    }

    if (useful_elements.size() != 0) {
      i = indx[useful_elements.GetMin()];
      useful_elements.extractMin();
    } else {
      i = j;
    }
  }
  return {ans0, ans};
}