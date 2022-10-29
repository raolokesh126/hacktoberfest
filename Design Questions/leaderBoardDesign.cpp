/**
 * Design a Leaderboard class, which has 3 functions:
 * addScore(playerId, score): Update the leaderboard by adding score
 * to the given player's score. If there is no player with such id in the leaderboard,
 * add him to the leaderboard with the given score.
 * top(K): Return the score sum of the top K players.
 * reset(playerId): Reset the score of the player with the given id to 0.
 * It is guaranteed that the player was added to the leaderboard before calling this function.
 * Initially, the leaderboard is empty.
**/
class Leaderboard {
public:
	Leaderboard() {}

	void addScore(int playerId, int score) {
		if (--scores[players[playerId]] <= 0) {
			scores.erase(players[playerId]);
		}
		players[playerId] += score;
		scores[players[playerId]] ++;
	}

	int top(int K) {
		int sum = 0;
		auto it = scores.end();
		for (; K > 0; it --) {
			if (it->second > 0) { // this check is optional
				for (int u = 0; u < min(it->second, K); u ++) {
					sum += it->first;
				}
				K -= it->second;
			}
		}
		return sum;
	}

	void reset(int playerId) {
		if (--scores[players[playerId]] <= 0) {
			scores.erase(players[playerId]);
		}
		players[playerId] = 0;
	}
private:
	unordered_map<int, int> players;
	map<int, int> scores;
};