Seed Known
	- It is assumed that the attacker knows the randomization string used to reorder the questions.
	- The subdirectories are organized by the seed used (permutations) and then by the number of answers known.
	runs go from 0 (no change in question order) to seed length 16 (decent password length), charset [a][A][0]
	- Actual attack difficulty and key security will vary case by case. Actual hard statistics are unknown until the
	password generation software is finalized, and even then results may vary.

Seed Unknown
	- It is assumed the attacker does not know the randomization string, but still knows the answers to (n) of the
	questions
	- Data is still arranged by the number of known answers.
