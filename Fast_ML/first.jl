# Implement simple linear regression using gradient descent and MLJ

using Pkg

Pkg.add("Plots")
Pkg.add("Statistics")
Pkg.add("MLJ")

using MLJ
using Plots
using Random

# Seed for reproducibility
Random.seed!(0)

# Generate synthetic data
n = 100
x = sort(5 * rand(n))  # 100 random numbers between 0 and 5
noise = 0.5 * randn(n)  # Gaussian noise
β_true = 2.5
β0_true = 1.0
y = β0_true .+ β_true .* x .+ noise

# Plot the generated data
scatter(x, y, label="Data points")

# Function to compute cost
function compute_cost(x, y, β0, β)
    n = length(y)
    predictions = β0 .+ β .* x
    cost = (1 / (2 * n)) * sum((predictions - y) .^ 2)
    return cost
end

# Gradient descent function
function gradient_descent(x, y, β0, β, learning_rate, iterations)
    n = length(y)
    for i in 1:iterations
        predictions = β0 .+ β .* x
        loss = predictions - y
        gradient_β0 = (1 / n) * sum(loss)
        gradient_β = (1 / n) * sum(loss .* x)
        β0 = β0 - learning_rate * gradient_β0
        β = β - learning_rate * gradient_β
    end
    return β0, β
end

# Initial parameters
β0_init = 0.0
β_init = 0.0
learning_rate = 0.01
iterations = 1000

# Perform gradient descent
β0_est, β_est = gradient_descent(x, y, β0_init, β_init, learning_rate, iterations)

# Plot the result
plot!(x, β0_est .+ β_est .* x, label="Fitted line")


# Prepare data for MLJ
data = DataFrame(X=x, Y=y)
model = @load LinearRegressor pkg=GLM

# Fit the model
mach = machine(model, data, :X, :Y)
fit!(mach)

# Extract fitted parameters
fitted_params = fitted_params(mach)
β0_mlj = fitted_params.intercept[1]
β_mlj = fitted_params.coefs[1]

# Plot the library model result
plot!(x, β0_mlj .+ β_mlj .* x, label="MLJ Fitted line")

# visualize all results
display(plot())

