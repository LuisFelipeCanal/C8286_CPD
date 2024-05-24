import aiohttp
import asyncio

async def fetch(session, url):
    async with session.get(url) as response:
        return await response.text()

async def main():
    urls = [
        'http://example.com',
        'http://example.org',
        'http://example.net',
    ]
    
    async with aiohttp.ClientSession() as session:
        tasks = [fetch(session, url) for url in urls]
        results = await asyncio.gather(*tasks)
        
        for result in results:
            print(result)

if __name__ == '__main__':
    asyncio.run(main())
