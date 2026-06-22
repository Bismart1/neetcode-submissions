class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // dist[i] = shortest time to reach node i
        // Initially, assume every node is unreachable
        vector<int> dist(n + 1, INT_MAX);

        // Source node k can be reached in 0 time
        dist[k] = 0;

        // Repeat the relaxation process (n-1) times
        // A shortest path can contain at most (n-1) edges
        for (int i = 0; i < n - 1; i++) {

            // To stop early if no distance changes in this pass
            bool updated = false;

            // Traverse all edges
            for (auto &edge : times) {

                // edge = {u, v, w}
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                // If u is reachable and going through u
                // gives a shorter path to v, update dist[v]
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {

                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }

            // No distance changed => all shortest paths found
            if (!updated)
                break;
        }

        // Find the maximum distance among all nodes
        int answer = 0;

        for (int i = 1; i <= n; i++) {

            // If some node was never reached
            if (dist[i] == INT_MAX)
                return -1;

            // Keep track of the farthest node
            answer = max(answer, dist[i]);
        }

        return answer;
    }
};