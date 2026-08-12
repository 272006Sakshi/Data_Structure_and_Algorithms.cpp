vector<int> parent;
vector<int> size;
// find parent node
int find(int x){
  if(x==parent[x]) return x;
  return parent[x] = find(parent[x]);
}

// Union
void Union(int x, int y){
  x_parent = find(x);
  y_parent = find(y);

  // agar dono ke parent same hai to koi baat hi nhi return kar denge
  if(x_parent == y_parent) return;
  // agr same nhi hai to size check karenge jiska size jayada hoga wo maalik (parent) banega
  if(size[x_parent]>size[y_parent]){
    parent[y_parent] = x_parent;
    // size increase hogi
    size[x_parent] += size[y_parent];
  }
  else if(size[x_parent]<size[y_parent]){
    parent[x_parent] = y_parent;
    // size increase hogi
    size[y_parent] += size[x_parent];
  }

  else{
   parent[x_parent] = y_parent;
   size[y_parent] += size[x_parent];
  }  
