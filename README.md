# DartsMonteCarloSimulation
Monte Carlo Simulation of 2 Player 501 Darts Game with Intelligent Strategy

I have created a Monte Carlo simulation of darts matches between two players, which are stored in an array of two player objects from the Player class. Each match consists of a loop over 13 sets. Player 0 is assumed to start throwing in each match and thereafter the players alternate throwing first in the sets of a match. Each set is a loop over games, played until one player has won a total of 3 games. Finally, during each game
the players take turns throwing up to 3 darts at the dartboard. This ‘game’ loop is exited when one player has reduced their score from 501 to 0, finishing by hitting a double field or the Bull’s Eye. At any point, the players’ scores are stored using an array of two score objects from the Score class.
Each throw is simulated with artificial intelligence—like in real life, the optimal score to target on the dartboard (e.g. 38) is determined according to the respective player’s current score using the throwDecision function in the ThrowDecision class. Next, using the actualTargetHit function from the same class, the optimal field on the dartboard to achieve this optimal score is determined (e.g. double 19). To ensure realistic intelligent optimal strategies, the ‘Out Chart’ from bargames101.com/wp-content/uploads/2016/10/The-01-Out-Chart_750x970.png (see right) underlies the construction of the two functions in the ThrowDecision class.
The throw at the determined target field is then implemented using the functions from the Board class, which simulate a throw at the (outer) Bull’s Eye or single/double/treble fields. The targeting accuracy when aiming at the (outer) Bull’s Eye and single/double/treble fields is a pre-determined percentage stored in each player object. These percentages allow to mimic players with varying performance. Together with the target field determined by the actualTargetHit function, this accuracy is passed to the Board class functions. These functions return the actual score hit by a player when targeting.
The actual score hit is obtained as follows: If the respective player hits doubles accurately with probability p, the probability to miss any double (1-p) is distributed amongst the neighbouring fields in approximate correspondence to their surface area (example on left for missed “double 19”). This area-dependant percentage has the advantage that the relative probability to hit a neighbour field is preserved when the targeting accuracy of a player is adjusted, mimicking reality. Further, if the actual target hit was double or Bull’s Eye, the throw is registered as a valid finishing throw. Should the actual throw have reduced a player’s game score to 0, the player has won the respective game. If however, the score 0 was
achieved by a treble, single, outer Bull’s Eye target hit, or if the player scores 1 or negatively, their score is reset to the score before their turn to throw and it’s the respective other player’s turn to throw up to thrice.
The number of sets won for player 1 are stored in an array (the other player’s matches won are not needed as sets played add to 13 and it is more efficient to only score player 1’s sets won). From this, the occurrences of final match scores over all of the matches are counted. This allows to output the frequency of match score occurrence over 10,000 matches and to find the most likely outcome (see “results” file).
