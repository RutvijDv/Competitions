#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 100000007;
double eps = 1e-12;
#define for0(i, e) for (ll i = 0; i < e; i++)
#define fors1(i, s, e) for (ll i = s; i < e; i++)
#define rfor0(i, s) for (ll i = s; i >= 0; i--)
#define rfor1(i, s, e) for (ll i = s; i >= e; i--)

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct Node
{
    ll data;
    struct Node *next;
    struct Node *prev;
    Node(int t)
    {
        data = t;
        next = prev = NULL;
    }
};

void deleteNode(Node **head_ref, Node *del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void show(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return;
}

void solve(Node *head, int q)
{
    Node *curr = head;
    for (int i = 0; i < q; i++)
    {
        int id, x, d1, d2;

        cin >> id;
        if (id == 1)
        {
            cin >> x;

            while (x--)
            {
                curr = curr->prev;
            }
        }

        if (id == 2)
        {
            cin >> x;

            while (x--)
            {
                curr = curr->next;
            }
        }

        if (id == 3)
        {
            cin >> d1 >> d2;

            deleteNode(&head, curr->next);
            insertAfter(curr, d2);
            insertAfter(curr, d1);
        }
    }

    return;
}

int main()
{
    fast_cin();

    ll n, q, x;
    cin >> n >> q;
    Node *head = NULL;
    Node *temp;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (head == NULL)
        {
            head = new Node(x);
            temp = head;
        }
        else
        {
            Node *curr = new Node(x);
            curr->prev = temp;
            temp->next = curr;
            temp = curr;
        }
    }

    solve(head, q);

    show(head);

    return 0;
}