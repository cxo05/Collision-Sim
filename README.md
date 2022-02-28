# Stochastic simulation of binary collisions of monoatomic gas molecules

The fundamental principles behind the physical properties of gases stems from the collision between the individual gas particles. There are various models to simulate the
collision between particles. The inverse power law model [2] is an accurate model of particle collisions but is considered a slow model due to the high computational time required at its conception. In 1981, Bird [1] introduced the Variable Hard Sphere (VHS) model as an approximation of the inverse power law model. In the VHS model, particles
interact only when they are in contact. In general, the VHS model is considered as a good approximation of the inverse power law model at room temperature. However, the difference between these two models has never been quantitatively demonstrated. This report discusses the implementation of these two models and their results when simulating the collision of gas particles at various temperatures and number densities. The result can provide a guide to estimate the reliability of results in the simulation of real gases. In our simulation, we use C++ programming language to implement both models. Averagely, the simulation of 2000 particle collisions is below 0.70 seconds.

[1] Vincenti and Kruger (1965). Introduction to physical gas dynamics.

[2] Bird, G.A. (1981). Monte Carlo simulation in an engineering context.
