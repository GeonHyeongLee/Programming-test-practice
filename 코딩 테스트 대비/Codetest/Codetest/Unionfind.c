#include <stdio.h>

#define MAX 1001

int parent[MAX]; // �� ������ �θ� �����ϴ� �迭
int rank[MAX]; // �� ������ ��ũ(Ʈ���� ����)�� �����ϴ� �迭


// �ʱ�ȭ : �� ������ �θ� �ڱ� �ڽ����� ����
void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

// Find : �־��� ������ ��Ʈ(��ǥ��)�� ã�� �Լ�
int find(int x) {
	if (parent[x] != x) {
		// ��� ����(Path Compression)
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

// Union : �� ���Ҹ� ���� �������� ��ġ�� �Լ�
void union_sets(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	// �� ���Ұ� �̹� ���� ���տ� ���ϸ� ��ġ�� ����
	if (rootX != rootY) {
		// ���Ͽ� by ��ũ(Union by Rank)
		// ��ũ�� ���� Ʈ���� ��ũ�� ū Ʈ�� �ؿ� ��ģ��
		if (rank[rootX] > rank[rootY]) {
			parent[rootY] = rootX;
		}
		else if (rank[rootX] < rank[rootY]) {
			parent[rootX] = rootY;
		}
		else {
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}
}

// �� ���Ұ� ���� ���տ� ���ϴ��� Ȯ���ϴ� �Լ�
int same_set(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	init(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (same_set(a, b)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
			union_sets(a, b);
		}
	}

	return 0;
}