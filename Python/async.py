import asyncio

async def coro(n):
    await asyncio.sleep(n)
    return n
async def main():
    tasks = [asyncio.create_task(coro(i)) for i in range(3)]
    results = await asyncio.gather(*tasks)
    print(results)

asyncio.run(main())