#define SOLD 1
#define UNSOLD -1
#define IN_PROGRESS 2
#define SUCCESS 10
#define FAILURE 11
struct _auction_
{
	int no_of_players;
	Player *players_on_auction; //list of all the players who are part of the auction;
	Team teamA;
	Team teamB;
	Team teamC;
	int SOLD_count;
	int UNSOLD_count;
};
typedef struct _auction_ Auction;

struct _team_
{
	int budget;
	int domestic_player_count;
	int international_player_count;
	int bench_strength; //Assumption: bench strength is limited to 10 players
	Player *players; //list of players in the respective teams
};
typedef struct _team_ Team;

struct _player_
{
	char name[20];
	int is_domestic; // 1 if player is domestic player, 0 if the player is international player
	double base_price;
	int bidding_status; // SOLD or UNSOLD or IN_PROGRESS
	char bid_team[6]; // final bid team
	double bid_price;

};
typedef struct _player_ Player;

Auction * initialisation();
int insert_player_to_auction(Auction *,Player); //inserting all the list of players who are taking part in the auction
Player search_by_name(Auction *,char []);
Player search_by_bid_status(int );
int start_auction(Auction *); //starts thee auction /bidding process by going through each players sequentially
void display_unsold_players(Auction *);

