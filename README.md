The program will then prompt the user to select a departure location by entering in the enumerated value associated with the desired location. The same list will be presented again with the exclusion of the previously selected location to allow the user to select a destination (However, there should not be a missing number from the list. For example, given the sample list above, if the departure was Miami, selection number 1, then when the list is presented again, Fargo should be listed as item 1.)

Once the user has selected both a departure and a destination location, we will compute the distance to both of those locations. This distance cannot be computed using typical Euclidean distance between two points, as we are dealing with points on the surface of a sphere. This will require us to use the Haversine formula to calculate distance across the surface of the sphere.

Learned a good amount from this.
