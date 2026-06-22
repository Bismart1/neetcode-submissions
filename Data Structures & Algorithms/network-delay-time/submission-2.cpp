class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Create adjacency list
        // adj[u] contains {v, weight}
        vector<vector<pair<int, int>>> adj(n + 1);

        // Fill the graph
        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // dist[i] = shortest time to reach node i
        vector<int> dist(n + 1, INT_MAX);

        // Starting node takes 0 time to reach
        dist[k] = 0;

        // Min heap: {time, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Start from node k
        pq.push({0, k});

        while (!pq.empty()) {

            // Get the node with the minimum time
            int currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // Explore all neighbors of currNode
            for (auto neighbor : adj[currNode]) {

                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // Time to reach nextNode through currNode
                int newTime = currTime + edgeWeight;

                // If we found a shorter path, update it
                if (newTime < dist[nextNode]) {

                    dist[nextNode] = newTime;

                    // Push updated distance into heap
                    pq.push({newTime, nextNode});
                }
            }
        }

        // Find the maximum time among all nodes
        int answer = 0;

        for (int i = 1; i <= n; i++) {

            // If some node was never reached
            if (dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};