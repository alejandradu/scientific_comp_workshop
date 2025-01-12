% Parameters
N = 20; % Lattice size NxN
numSteps = 10000; % Number of Monte Carlo steps
J = randn(N); % Interaction matrix with random values for ferro/antiferro behavior
T = 1; % Temperature (arbitrary units)

% Initialize spins randomly
spins = randi([0 1], N, N) * 2 - 1; % Generates a matrix of +1 and -1

% Initialize figure for visualization
figure;
colormap([1, 0, 0; 0, 0, 1]); % Red for -1, Blue for +1

function spins = metropolis(spins, J, T, N)
    for step = 1:N^2
        i = randi(N);
        j = randi(N);

        % Calculate the change in energy if spin (i,j) is flipped
        dE = 2 * spins(i,j) * sum(J(i,j) * spins(mod(i-2:N+i-2, N) + 1, mod(j-2:N+j-2, N) + 1));

        % Metropolis criterion
        if dE < 0 || rand() < exp(-dE / T)
            spins(i,j) = -spins(i,j);
        end
    end
end

% Main simulation loop
for step = 1:numSteps
    spins = metropolis(spins, J, T, N);
    
    % Update visualization every 100 steps
    if mod(step, 100) == 0
        imagesc(spins);
        title(['Step ', num2str(step)]);
        axis equal tight;
        drawnow;
    end
end
